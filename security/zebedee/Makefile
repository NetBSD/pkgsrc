# $NetBSD: Makefile,v 1.1.1.1 2001/06/24 05:48:51 taca Exp $
#

DISTNAME=		zebedee-2.2.2
CATEGORIES=		security
MASTER_SITES=		http://www.winton.org.uk/zebedee/ \
			http://prdownloads.sourceforge.net/zebedee/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.winton.org.uk/zebedee/
COMMENT=		Simple tunneling program for TCP or UDP with encryption

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=		tcl>=${TCL_REQD}:../../lang/tcl		# need runtime

USE_SSL=		# defined

MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
