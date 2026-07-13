# $NetBSD: Makefile,v 1.23 2026/07/13 04:35:24 wiz Exp $

DISTNAME=	sphinxtrain-1.0.8
PKGREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmusphinx.sourceforge.net/
COMMENT=	CMUSphinx speed recognition acoustic model training tools
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run pkg-config

CONFIGURE_ARGS+=	--with-sphinxbase=auto

REPLACE_PERL+=		scripts/*/*.pl
REPLACE_PYTHON+=	python/cmusphinx/*.py			\
			python/setup.py				\
			scripts/0000.g2p_train/calculateER.py	\
			scripts/0000.g2p_train/evaluate.py	\
			scripts/sphinxtrain

.include "../../audio/sphinxbase/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
