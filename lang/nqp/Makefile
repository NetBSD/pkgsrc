# $NetBSD: Makefile,v 1.24 2020/08/31 18:09:51 wiz Exp $

DISTNAME=	nqp-2020.02.1
PKGREVISION=	1
CATEGORIES=	lang perl6
#MASTER_SITES=	${MASTER_SITE_GITHUB:=perl6/}
MASTER_SITES=	https://github.com/perl6/nqp/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
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

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
