# $NetBSD: Makefile,v 1.8 2003/07/17 21:33:04 grant Exp $
#
# This package is a placeholder to signify that the base PHP3 package already
# has the PCRE functionality.  It *must* have the same version number as the
# PHP3 package.
#
DISTNAME=		php-pcre-${BASE_VERS}
BASE_VERS=		3.0.18
PKGREVISION=		1
CATEGORIES=		www php3 devel
DISTFILES=		# empty

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP3 extension for Perl-compatible regular expressions

DEPENDS+=		php-${BASE_VERS}nb2:../../www/php3

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
