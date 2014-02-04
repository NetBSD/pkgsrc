# $NetBSD: Makefile,v 1.30 2014/02/04 00:19:54 joerg Exp $
#

DISTNAME=	ttt-1.8.2
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sonycsl.co.jp/pub/kjc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sonycsl.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=	install install-man
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			exec_prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

REPLACE_INTERPRETER+=		sys-BLTWISH
REPLACE.sys-BLTWISH.old=	.*bltwish
REPLACE.sys-BLTWISH.new=	${PREFIX}/bin/bltwish
REPLACE_FILES.sys-BLTWISH=	ttt.tcl


.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DUSE_INTERP_RESULT
CONFIGURE_ARGS+=	ttt_cv_prog_cflags=${CFLAGS:Q}

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56]*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
