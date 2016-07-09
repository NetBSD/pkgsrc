# $NetBSD: Makefile,v 1.16 2016/07/09 06:38:37 wiz Exp $
#

DISTNAME=	rlwrap-0.42
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://utopia.knoware.nl/~hlub/uck/rlwrap/
COMMENT=	Provides command line editing and history for other commands
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

REPLACE_PERL+=	filters/censor_passwords
REPLACE_PERL+=	filters/count_in_prompt
REPLACE_PERL+=	filters/ftp_filter
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

TEST_TARGET=		check

.include "options.mk"
.include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_API_DEPENDS.readline+=readline>=4.2
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
