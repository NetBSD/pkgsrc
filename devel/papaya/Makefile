# $NetBSD: Makefile,v 1.8 2004/04/22 05:38:32 minskim Exp $
#

DISTNAME=	papaya-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/		\
		${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~em7t-hmd/papaya/index.html
COMMENT=	Simple scripts for software development

BUILD_DEPENDS+=	texi2html-[0-9]*:../../textproc/texi2html

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	run
NO_BUILDLINK=	YES
USE_LANGUAGES=	# empty
GNU_CONFIGURE=	YES
INFO_FILES=	papaya.info

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

.include "../../mk/bsd.pkg.mk"
