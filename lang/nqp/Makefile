# $NetBSD: Makefile,v 1.37 2022/01/23 14:07:05 mef Exp $

DISTNAME=	nqp-2021.12
CATEGORIES=	lang perl6
#ASTER_SITES=	${MASTER_SITE_GITHUB:=perl6/}
MASTER_SITES=	https://github.com/perl6/nqp/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
COMMENT=	Not Quite Perl -- lightweight Perl 6-like environment for VM
LICENSE=	artistic-2.0

DEPENDS+=	MoarVM>=2021.09:../../devel/MoarVM

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--backends=moar

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
