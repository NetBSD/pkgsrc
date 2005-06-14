# $NetBSD: Makefile,v 1.242 2005/06/14 03:52:01 rillig Exp $
#

DISTNAME=	pkglint-4.17.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Documentation/pkgsrc/
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl
TOOLS_DEPMETHOD.perl=	DEPENDS

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_TOOLS=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin man/cat1 man/man1 share/pkglint

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	lintpkgsrc.0 lintpkgsrc.1 lintpkgsrc.pl
SUBST_FILES.pkglint+=	pkglint.0 pkglint.1 pkglint.pl
SUBST_FILES.pkglint+=	plist-clash.pl
SUBST_SED.pkglint+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.pkglint+=	-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'
SUBST_SED.pkglint+=	-e 's|@DISTVER@|${DISTNAME:S/pkglint-//}|g'
SUBST_SED.pkglint+=	-e 's|@MAKE@|${MAKE}|g'
SUBST_SED.pkglint+=	-e 's|@PERL@|${PERL5}|g'
SUBST_SED.pkglint+=	-e 's|@DATADIR@|${PREFIX}/share/pkglint|g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "AIX" || ${OPSYS} == "SunOS"
MANINSTALL=		catinstall
.endif

do-extract:
.for _f_ in ${SUBST_FILES.pkglint}
	@${CP} ${FILESDIR}/${_f_} ${WRKSRC}/${_f_}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint.pl ${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc.pl ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash.pl ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${PREFIX}/man/cat1
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${PREFIX}/man/man1
.endif
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${PREFIX}/man/cat1
	${INSTALL_DATA} ${FILESDIR}/makevars.map ${PREFIX}/share/pkglint/
	${INSTALL_DATA} ${FILESDIR}/deprecated.map ${PREFIX}/share/pkglint/

.include "../../mk/bsd.pkg.mk"
