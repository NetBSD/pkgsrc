# $NetBSD: Makefile,v 1.20 2006/10/04 21:36:00 wiz Exp $
#

DISTNAME=	papaya-0.1.7
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/papaya-utils/
COMMENT=	Simple scripts for software development

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# none, not even C
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	gzip_command=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=	sh_command=${TOOLS_SH:Q}
CONFIGURE_ENV+=	tar_command=${TOOLS_TAR:Q}
CONFIGURE_ENV+=	texi2html_command=${TOOLS_PATH.texi2html:Q}
USE_TOOLS+=	sh perl:run tar texi2html
INFO_FILES=	# PLIST

CONFIGURE_ENV+=	perl_command=${PERL5:Q}

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${PREFIX}/share/doc/papaya

.include "../../mk/bsd.pkg.mk"
