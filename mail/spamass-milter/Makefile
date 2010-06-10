# $NetBSD: Makefile,v 1.30 2010/06/10 12:30:21 gdt Exp $
#

DISTNAME=	spamass-milter-0.3.1
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

# This patch is taken from upstream CVS, and is from the 0.3.1 release
# tag to head of CVS on 5 Jun 2010, although CVS last changed on 24
# Jul 2006.  The patch fixes an error in formatting of the synthetic
# Received: line.  The patch is a patchfile (hosted on ftp.netbsd.org)
# instead of a pkgsrc patch because it is something upstream would
# have released if upstream were still maintaining this code.
PATCHFILES=	spamass-milter-001.patch

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
