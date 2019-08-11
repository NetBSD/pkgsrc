# $NetBSD: Makefile,v 1.4 2019/08/11 13:23:26 wiz Exp $

DISTNAME=	MultiMarkdown-4-4.7.1
PKGNAME=	${DISTNAME:S/MultiMarkdown-4-/multimarkdown-/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://fletcherpenney.net/multimarkdown/
COMMENT=	MultiMarkdown (MMD) v4 written in C
LICENSE=	gnu-gpl-v3 OR mit

USE_TOOLS+=	gmake perl

MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_TARGET=	ALL
INSTALL_TARGET=	pkg-install pkg-install-scripts

REPLACE_PERL=	enumsToPerl.pl

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing /usr/local paths.
SUBST_FILES.fix-paths=		scripts/m*
SUBST_SED.fix-paths=		-e 's,"/usr/local,"${PREFIX},g'

post-patch:
	cd ${WRKSRC} && \
	${RM} scripts/markdown.bat scripts/mmd2pdf.orig

.include "../../mk/bsd.pkg.mk"
