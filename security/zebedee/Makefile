# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		zebedee-2.3.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.winton.org.uk/zebedee/ \
			${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.winton.org.uk/zebedee/
COMMENT=		Simple tunneling program for TCP or UDP with encryption

DEPENDS+=		tcl-[0-9]*:../../lang/tcl

USE_PERL5=		build
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes

MAKE_ENV+=		PERL5=${PERL5}
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
