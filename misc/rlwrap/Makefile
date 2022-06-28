# $NetBSD: Makefile,v 1.29 2022/06/28 11:34:52 wiz Exp $
#

DISTNAME=	rlwrap-0.45.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hanslub42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hanslub42/rlwrap
COMMENT=	Provides command line editing and history for other commands
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_TOOLS+=		autoreconf autoconf automake

REPLACE_PERL+=	filters/censor_passwords
REPLACE_PERL+=	filters/count_in_prompt
REPLACE_PERL+=	filters/debug_null
REPLACE_PERL+=	filters/edit_history
REPLACE_PERL+=	filters/ftp_filter
REPLACE_PERL+=	filters/handle_hotkeys
REPLACE_PERL+=	filters/history_format
REPLACE_PERL+=	filters/listing
REPLACE_PERL+=	filters/logger
REPLACE_PERL+=	filters/null
REPLACE_PERL+=	filters/outfilter
REPLACE_PERL+=	filters/paint_prompt
REPLACE_PERL+=	filters/pipeline
REPLACE_PERL+=	filters/pipeto
REPLACE_PERL+=	filters/scrub_prompt
REPLACE_PERL+=	filters/simple_macro
REPLACE_PERL+=	filters/template
REPLACE_PERL+=	filters/unbackspace

REPLACE_PYTHON+=	filters/*.py
REPLACE_PYTHON+=	filters/dissect_prompt
REPLACE_PYTHON+=	filters/handle_sigwinch
REPLACE_PYTHON+=	filters/makefilter

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/rlwrap/filters/README
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/rlwrap/filters/RlwrapFilter.3pm
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/rlwrap/filters/RlwrapFilter.pm

BUILDLINK_API_DEPENDS.readline+=readline>=4.2
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
