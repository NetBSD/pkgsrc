# $NetBSD: Makefile,v 1.5 2002/03/25 00:34:12 jmc Exp $
#

DISTNAME=		zebedee-2.3.1
CATEGORIES=		security
MASTER_SITES=		http://www.winton.org.uk/zebedee/ \
			http://prdownloads.sourceforge.net/zebedee/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.winton.org.uk/zebedee/
COMMENT=		Simple tunneling program for TCP or UDP with encryption

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=		# defined
USE_BUILDLINK_ONLY=	# defined

MAKE_ENV+=		PERL5=${PERL5}
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
