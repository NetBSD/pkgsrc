# $NetBSD: Makefile,v 1.3 2013/10/19 09:06:55 adam Exp $

DISTNAME=	nqp-2013.08
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
			--with-parrot=${PREFIX}/bin/parrot

PLIST_SUBST+=		PARROT_VERSION=${PARROT_VERSION:Q}
PRINT_PLIST_AWK+=        { gsub(/${PARROT_VERSION}/, "$${PARROT_VERSION}") }

.include "../../lang/parrot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
