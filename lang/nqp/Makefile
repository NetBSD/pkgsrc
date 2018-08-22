# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:21 wiz Exp $

DISTNAME=	nqp-2017.09
PKGREVISION=	1
CATEGORIES=	lang perl6
MASTER_SITES=	http://rakudo.org/downloads/nqp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rakudo.org/
COMMENT=	Not Quite Perl -- lightweight Perl 6-like environment for VM
LICENSE=	artistic-2.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--backends=moar

BUILDLINK_API_DEPENDS.MoarVM+=  MoarVM>=2017.07
.include "../../devel/MoarVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
