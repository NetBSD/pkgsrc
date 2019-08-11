# $NetBSD: Makefile,v 1.16 2019/08/11 13:21:23 wiz Exp $

DISTNAME=	rakudo-star-2013.08
PKGREVISION=	14
CATEGORIES=	lang perl6
MASTER_SITES=	http://rakudo.org/downloads/star/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rakudo.org/
COMMENT=	Perl 6 reference implementation
LICENSE=	artistic-2.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
PLIST_SRC+=		${PLIST_SRC_DFLT}
.if (${OPSYS} != "Darwin")
PLIST_SRC+=		PLIST.shared
.else
USE_TOOLS+=		 gmake
.endif

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--with-nqp=${PREFIX}/bin/nqp

PLIST_SUBST+=		PARROT_VERSION=${PARROT_VERSION:Q}
PRINT_PLIST_AWK+=        { gsub(/${PARROT_VERSION}/, "$${PARROT_VERSION}") }

.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
