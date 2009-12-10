# $NetBSD: Makefile,v 1.69 2009/12/10 20:26:33 abs Exp $
#

DISTNAME=	pkgdiff-0.122
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Tools to create, maintain and send back patches for pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

MAKE_ENV+=	PKGSRCDIR=${_PKGSRCDIR:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1"
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DIFF?=		${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
.else
DIFF?=		diff
.endif
.if ${OPSYS} == "SunOS"
MANINSTALL=	catinstall
.endif

INSTALLATION_DIRS=	bin
.if !empty(MANINSTALL:Mcatinstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
.endif

do-build:
.for FILE in mkpatches patchdiff
	${SED}	-e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PERL5@|${PERL5}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
		< ${FILESDIR}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
	${SED} -e 's|@DIFF@|${DIFF}|g'			\
		-e 's|@SH@|${SH}|g'			\
		< ${FILESDIR}/pkgdiff			\
		> ${WRKSRC}/pkgdiff
	${CP} ${FILESDIR}/pkgvi ${WRKSRC}
	${CP} ${FILESDIR}/feedback-patches ${WRKSRC}
.if !empty(MANINSTALL:Mcatinstall)
.  for FILE in mkpatches patchdiff pkgdiff pkgvi feedback-patches
	${CP} ${FILESDIR}/${FILE}.0 ${WRKSRC}/${FILE}.0
.  endfor
.endif

do-install:
.for FILE in mkpatches patchdiff pkgdiff pkgvi feedback-patches
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${DESTDIR}${PREFIX}/bin
.   if !empty(MANINSTALL:Mcatinstall)
	${INSTALL_MAN} ${WRKSRC}/${FILE}.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.   endif
.   if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${FILESDIR}/${FILE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.   endif
.endfor

.include "../../mk/bsd.pkg.mk"
