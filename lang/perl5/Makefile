# $NetBSD: Makefile,v 1.37 2001/06/07 04:25:33 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		perl-${PERL5_VERS}
PERL5_PKG_VERS=		# empty
CATEGORIES+=		lang devel
DISTFILES=		# empty

HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Practical Extraction and Report Language

DEPENDS+=		perl-base>=${PERL5_DIST_VERS}:../../lang/perl5-base
DEPENDS+=		p5-CGI>=2.75.2:../../www/p5-CGI
DEPENDS+=		perl-mk-1.1:../../pkgtools/perl-mk

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
