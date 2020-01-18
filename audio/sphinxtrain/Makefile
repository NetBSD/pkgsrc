# $NetBSD: Makefile,v 1.8 2020/01/18 23:30:06 rillig Exp $

DISTNAME=	sphinxtrain-1.0.8
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	fhajny@NetBSD.org
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
