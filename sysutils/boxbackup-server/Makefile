# $NetBSD: Makefile,v 1.1.1.1 2008/06/21 15:04:35 drochner Exp $
#

DISTNAME=	boxbackup-0.10
PKGNAME=	boxbackup-server-0.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=boxbackup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.boxbackup.org/
COMMENT=	Backup tool

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	perl:run

REPLACE_PERL+=	bin/bbstored/bbstored-certs bin/bbstored/bbstored-config
REPLACE_PERL+=	lib/raidfile/raidfile-config

INSTALL_TARGET=	install-backup-server

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
