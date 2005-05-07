# $NetBSD: Makefile,v 1.233 2005/05/07 22:24:04 wiz Exp $
#

DISTNAME=	pkglint-4.13
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	yes

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

DISTVER=	${DISTNAME:S/pkglint-//}

INSTALLATION_DIRS=	bin man/cat1 man/man1 share/pkglint

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	pre-build
SUBST_FILES.pkglint+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
SUBST_FILES.pkglint+=	pkglint.0 pkglint.1 pkglint.pl
SUBST_FILES.pkglint+=	plist-clash.pl
SUBST_SED.pkglint+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.pkglint+=	-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'
SUBST_SED.pkglint+=	-e 's|@DISTVER@|${DISTVER}|g'
SUBST_SED.pkglint+=	-e 's|@MAKE@|${MAKE}|g'
SUBST_SED.pkglint+=	-e 's|@PERL@|${PERL5}|g'
SUBST_SED.pkglint+=	-e 's|@DATADIR@|${PREFIX}/share/pkglint|g'

.include "../../mk/bsd.prefs.mk"

do-extract:
.for _f_ in ${SUBST_FILES.pkglint}
	@${CP} ${FILESDIR}/${_f_} ${WRKSRC}/${_f_}
.endfor

do-build:
	@${DO_NADA}
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
	${INSTALL_DATA} ${FILESDIR}/makevars.map ${PREFIX}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR}/deprecated.map ${PREFIX}/share/pkglint/

.include "../../mk/bsd.pkg.mk"
