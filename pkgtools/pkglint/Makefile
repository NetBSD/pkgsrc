# $NetBSD: Makefile,v 1.185 2004/04/24 00:17:20 reed Exp $
#

DISTNAME=	pkglint-3.73
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	yes

WRKSRC=		${WRKDIR}
NO_BUILDLINK=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

MAKE_ENV=	PKGSRCDIR=${_PKGSRCDIR:Q}

DISTVER=	${DISTNAME:S/pkglint-//}

INSTALLATION_DIRS=	bin man/cat1 man/man1

SUBST_FILES=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl pkglint.1 pkglint.0
SUBST_FILES+=	pkglint.pl plist-clash.pl

.include "../../mk/bsd.prefs.mk"

do-build:
	@${MKDIR} ${WRKSRC}/src
.for FILE in ${SUBST_FILES}
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${_PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
		-e 's|@PERL@|${PERL5}|g'		\
		${FILESDIR}/${FILE} > ${WRKSRC}/${FILE}
.endfor
.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
   # the pre-generated man-pages are 'mandoc';  these OS need 'man'
.  for FILE in lintpkgsrc pkglint
	nroff -man ${WRKSRC}/${FILE}.1 > ${WRKSRC}/${FILE}.0
.  endfor
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint.pl ${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc.pl ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash.pl ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
