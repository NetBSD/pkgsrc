# $NetBSD: Makefile,v 1.10 2005/03/02 14:11:28 wiz Exp $
#

DISTNAME=	papaya-0.1.7
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/		\
		${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/index.html
COMMENT=	Simple scripts for software development

BUILD_DEPENDS+=	texi2html>=1.76:../../textproc/texi2html

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	run
NO_BUILDLINK=	YES
USE_LANGUAGES=	# empty
GNU_CONFIGURE=	YES
INFO_FILES=	papaya.info

CONFIGURE_ENV+=	perl_command=${PERL5:Q}

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${PREFIX}/share/doc/papaya

.include "../../mk/bsd.pkg.mk"
