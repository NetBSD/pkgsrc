# $NetBSD: Makefile,v 1.5.2.3 2002/08/25 21:21:14 jlam Exp $
#

DISTNAME=		zebedee-2.3.1
CATEGORIES=		security
MASTER_SITES=		http://www.winton.org.uk/zebedee/ \
			${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.winton.org.uk/zebedee/
COMMENT=		Simple tunneling program for TCP or UDP with encryption

USE_PERL5=		build
USE_GMAKE=		# defined
USE_BUILDLINK2=		# defined

MAKE_ENV+=		PERL5=${PERL5}
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
