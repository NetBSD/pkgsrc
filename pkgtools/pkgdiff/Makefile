# $NetBSD: Makefile,v 1.77 2012/09/11 23:19:38 asau Exp $
#

DISTNAME=	pkgdiff-1.3
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Tools to create, maintain, and send back patches for pkgsrc
LICENSE=	2-clause-bsd AND original-bsd

PKG_INSTALLATION_TYPES= overwrite pkgviews

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

MAKE_ENV+=	PKGSRCDIR=${_PKGSRCDIR:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1"
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DIFF?=		${PREFIX}/bin/gdiff
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
.for f in mkpatches patchdiff
	${SED}	-e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PERL5@|${PERL5}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
		< ${FILESDIR}/${f}.pl			\
		> ${WRKSRC}/${f}
.endfor
	${SED} -e 's|@DIFF@|${DIFF}|g'			\
		-e 's|@SH@|${SH}|g'			\
		< ${FILESDIR}/pkgdiff			\
		> ${WRKSRC}/pkgdiff
	${CP} ${FILESDIR}/pkgvi ${WRKSRC}
	${CP} ${FILESDIR}/feedback-patches ${WRKSRC}
.if !empty(MANINSTALL:Mcatinstall)
.  for f in mkpatches patchdiff pkgdiff pkgvi feedback-patches
	${CP} ${FILESDIR}/${f}.0 ${WRKSRC}/${f}.0
.  endfor
.endif

do-install:
.for f in mkpatches patchdiff pkgdiff pkgvi feedback-patches
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.  if !empty(MANINSTALL:Mcatinstall)
	${INSTALL_MAN} ${WRKSRC}/${f}.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.  if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${FILESDIR}/${f}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
