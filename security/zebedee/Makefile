# $NetBSD: Makefile,v 1.3 2001/07/15 16:52:02 jlam Exp $
#

DISTNAME=		zebedee-2.2.2
CATEGORIES=		security
MASTER_SITES=		http://www.winton.org.uk/zebedee/ \
			http://prdownloads.sourceforge.net/zebedee/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.winton.org.uk/zebedee/
COMMENT=		Simple tunneling program for TCP or UDP with encryption

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=		tcl>=8.3.2:../../lang/tcl

USE_BUILDLINK_ONLY=	# defined

MAKE_ENV+=		OPTIM="${CFLAGS}"
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
