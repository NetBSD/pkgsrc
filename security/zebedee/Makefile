# $NetBSD: Makefile,v 1.20 2005/05/22 20:08:31 jlam Exp $

DISTNAME=	zebedee-2.5.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.winton.org.uk/zebedee/
COMMENT=	Simple tunneling program for TCP or UDP with encryption

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

USE_TOOLS+=		gmake
USE_PERL5=		build

MAKE_ENV+=		PERL5=${PERL5}
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
