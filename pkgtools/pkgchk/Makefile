# $NetBSD: Makefile,v 1.1.1.1 2001/07/02 14:12:29 abs Exp $
#

DISTNAME=		pkgchk-1.00
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=		Check installed package versions against pkgsrc

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkgchk.sh ${PREFIX}/sbin/pkgchk
	${INSTALL_MAN} ${FILESDIR}/pkgchk.8 ${PREFIX}/man/man8/pkgchk.8

.include "../../mk/bsd.pkg.mk"
