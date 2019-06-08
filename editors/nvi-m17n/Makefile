# $NetBSD: Makefile,v 1.56 2019/06/08 10:40:57 rillig Exp $

DISTNAME=	nvi-1.79
PKGNAME=	nvi-m17n-1.79.20040608
PKGREVISION=	7
CATEGORIES=	editors
MASTER_SITES=	http://www.bostic.com/files/

PATCH_SITES=	ftp://ftp.itojun.org/pub/nvi/
PATCHFILES=	nvi-m17n-1.79-20040608.diff.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Clone of vi/ex, with multilingual patch

CONFLICTS=	vigor-[0-9]* nvi-[0-9]*

CONFIGURE_DIRS=	build
GNU_CONFIGURE=	YES

PATCH_DIST_ARGS+=	-d ${WRKSRC} --forward --quiet -E -f
PATCH_FUZZ_FACTOR=	-F1

CONFIGURE_ENV+=		OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS+=	--enable-multibyte --program-prefix=n

CONFIGURE_ENV+=	vi_cv_path_shell=${TOOLS_SH}
CONFIGURE_ENV+=	vi_cv_path_perl=${TOOLS_PATH.perl}
USE_TOOLS+=	sh perl:run

CPPFLAGS+=		-DGTAGS
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "options.mk"

AUTODETECT.big5=	cn
AUTODETECT.euc-cn=	cn
AUTODETECT.euc-jp=	jp
AUTODETECT.euc-kr=	kr
AUTODETECT.euc-tw=	tw
AUTODETECT.hz=		cn
AUTODETECT.iso-2022-cn=	cn
AUTODETECT.iso-2022-jp=	jp
AUTODETECT.iso-2022-kr=	kr
AUTODETECT.sjis=	jp

ENCODINGS+=	iso-2022-cn iso-2022-jp iso-2022-kr
ENCODINGS+=	euc-jp euc-cn euc-kr sjis big5 euc-tw hz

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
# XXX ignore NetBSD 2.0F and later's grantpt(3) and SysV pty for just now
CONFIGURE_ENV+=		vi_cv_sys5_pty=no
.endif

post-patch:
# DragonFly has no CIRCLEQ_* so it wants the provided <sys/queue.h>
.if ${OPSYS} == "NetBSD" || \
    ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "OpenBSD"
	${RM} -f ${WRKSRC}/include/sys/queue.h
.endif

post-build:
.for encoding in ${ENCODINGS}
	@${SED} -e 's|$${CANNA_OPT}|${CANNA_OPT.${encoding}}|'		\
		-e 's|$${AUTODETECT}|${AUTODETECT.${encoding}}|'	\
		-e 's|$${ENCODING}|${encoding}|g'			\
		-e 's|$${PREFIX}|${PREFIX}|'				\
		${FILESDIR}/nvi-m17n > ${WRKDIR}/nvi-${encoding}
.endfor

post-install:
.for encoding in ${ENCODINGS}
	${INSTALL_SCRIPT} ${WRKDIR}/nvi-${encoding} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.english \
		${DESTDIR}${PREFIX}/share/vi/
	${INSTALL_DATA} ${WRKSRC}/README.japanese \
		${DESTDIR}${PREFIX}/share/vi/

.include "../../mk/bsd.pkg.mk"
