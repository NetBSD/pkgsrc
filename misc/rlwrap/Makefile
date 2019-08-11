# $NetBSD: Makefile,v 1.22 2019/08/11 13:21:59 wiz Exp $
#

DISTNAME=	rlwrap-0.43
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hanslub42/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hanslub42/rlwrap
COMMENT=	Provides command line editing and history for other commands
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_TOOLS+=		autoreconf autoconf automake

REPLACE_PERL+=	filters/censor_passwords
REPLACE_PERL+=	filters/count_in_prompt
REPLACE_PERL+=	filters/ftp_filter
REPLACE_PERL+=	filters/handle_hotkeys
REPLACE_PERL+=	filters/history_format
REPLACE_PERL+=	filters/listing
REPLACE_PERL+=	filters/logger
REPLACE_PERL+=	filters/null
REPLACE_PERL+=	filters/paint_prompt
REPLACE_PERL+=	filters/pipeline
REPLACE_PERL+=	filters/pipeto
REPLACE_PERL+=	filters/scrub_prompt
REPLACE_PERL+=	filters/simple_macro
REPLACE_PERL+=	filters/template
REPLACE_PERL+=	filters/unbackspace

REPLACE_PYTHON+=	filters/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

BUILDLINK_API_DEPENDS.readline+=readline>=4.2
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
