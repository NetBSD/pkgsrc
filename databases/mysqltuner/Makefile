# $NetBSD: Makefile,v 1.10 2022/06/28 11:31:19 wiz Exp $

GITHUB_PROJECT=	MySQLTuner-perl
DISTNAME=	1.7.2
PKGNAME=	mysqltuner-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=major/}
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mysqltuner.com/
COMMENT=	Perl script that assists in MySQL configuration
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes
USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_LANGUAGES=	# none

REPLACE_PERL=	mysqltuner.pl

PKGDOCDIR=		share/doc/${PKGBASE}
SUBST_CLASSES+=		docdir
SUBST_FILES.docdir=	mysqltuner.pl
SUBST_MESSAGE.docdir=	Fixing DOCDIR.
SUBST_SED.docdir=	-e "s|/usr/share/mysqltuner|${PREFIX}/${PKGDOCDIR}|1"
SUBST_STAGE.docdir=	pre-configure

INSTALLATION_DIRS+=	bin ${PKGDOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysqltuner.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/basic_passwords.txt \
		${DESTDIR}${PREFIX}/${PKGDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${DESTDIR}${PREFIX}/${PKGDOCDIR}

.include "../../mk/bsd.pkg.mk"
