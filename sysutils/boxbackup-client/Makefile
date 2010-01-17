# $NetBSD: Makefile,v 1.3 2010/01/17 12:02:45 wiz Exp $
#

DISTNAME=	boxbackup-0.10
PKGNAME=	boxbackup-client-0.10
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=boxbackup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.boxbackup.org/
COMMENT=	Backup tool

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	perl:run

REPLACE_PERL+=	bin/bbackupd/bbackupd-config

INSTALL_TARGET=	install-backup-client

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
