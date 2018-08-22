# $NetBSD: Makefile,v 1.36 2018/08/22 09:44:58 wiz Exp $
#

DISTNAME=	papaya-0.1.7
PKGREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=papaya-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/papaya-utils/
COMMENT=	Simple scripts for software development

USE_LANGUAGES=	# none, not even C
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	gzip_command=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=	sh_command=${TOOLS_SH:Q}
CONFIGURE_ENV+=	tar_command=${TOOLS_TAR:Q}
CONFIGURE_ENV+=	texi2html_command=${TOOLS_PATH.texi2html:Q}
CONFIGURE_ENV+=	gmake_command=${TOOLS_PATH.gmake}
USE_TOOLS+=	sh perl:run tar texi2html gmake:run gzip:run makeinfo
INFO_FILES=	yes

CONFIGURE_ENV+=	perl_command=${PERL5:Q}

pre-configure:
	cd ${WRKSRC}/src &&						\
	${CP} detab.in detab.in.cr &&					\
	${TR} -d '\r' < detab.in.cr > detab.in

# let not to be regenerated from patched papaya.texi file.
post-patch:
	${TOUCH} ${WRKSRC}/doc/papaya.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${WRKSRC}/doc/papaya/*.html ${DESTDIR}${PREFIX}/share/doc/papaya

.include "../../mk/bsd.pkg.mk"
