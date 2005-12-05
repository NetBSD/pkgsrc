# $NetBSD: Makefile,v 1.59 2005/12/05 20:50:51 rillig Exp $
#

DISTNAME=	pkgdiff-0.118
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Tools to create, maintain and send back patches for pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

MAKE_ENV+=	PKGSRCDIR=${_PKGSRCDIR:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

.if ${OPSYS} == "SunOS"
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DIFF?=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}diff
MANINSTALL=
.else
DIFF?=		diff
.endif

INSTALLATION_DIRS=	bin
.if !empty(MANINSTALL:Mcatinstall)
INSTALLATION_DIRS+=	man/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
INSTALLATION_DIRS+=	man/man1
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
.    if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	nroff -man ${FILESDIR}/${FILE}.1 >${WRKSRC}/${FILE}.0
.    else
	${CP} ${FILESDIR}/${FILE}.0 ${WRKSRC}/${FILE}.0
.    endif
.  endfor
.endif

do-install:
.for FILE in mkpatches patchdiff pkgdiff pkgvi feedback-patches
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.   if !empty(MANINSTALL:Mcatinstall)
	${INSTALL_MAN} ${WRKSRC}/${FILE}.0 ${PREFIX}/man/cat1
.   endif
.   if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${FILESDIR}/${FILE}.1 ${PREFIX}/man/man1
.   endif
.endfor

.include "../../mk/bsd.pkg.mk"
