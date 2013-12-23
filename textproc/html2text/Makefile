# $NetBSD: Makefile,v 1.18 2013/12/23 11:57:06 wiz Exp $

DISTNAME=	html2text-1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	http://www.mbayer.de/html2text/downloads/	\
		${MASTER_SITE_SUNSITE:=apps/www/converters/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mbayer.de/html2text/
COMMENT=	Advanced HTML-to-text converter
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gunzip
GCC_REQD+=		3.0
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		ECHO=${ECHO:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

SUBST_CLASSES+=		configure
SUBST_STAGE.configure=	pre-configure
SUBST_MESSAGE.configure=Fixing 'configure' script
SUBST_FILES.configure=	configure
SUBST_SED.configure=	-e 's,^$$echo,$$echo -n,'
SUBST_SED.configure+=	-e 's,\\c,,'
SUBST_SED.configure+=	-e 's,$$CXX $$tmp_file.C,$$CXX $$LDFLAGS $$tmp_file.C,'

post-build:
	${GUNZIP_CMD} -d ${WRKSRC}/html2text.1.gz ${WRKSRC}/html2textrc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
