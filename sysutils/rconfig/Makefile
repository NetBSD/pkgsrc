# $NetBSD: Makefile,v 1.1.1.1 2001/12/31 11:45:35 abs Exp $

DISTNAME=	rconfig-0.05
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configuration files for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	perl>=5.0:../../lang/perl5
DEPENDS+=	srsh-[0-9]*:../../net/srsh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rconfig.pl ${PREFIX}/sbin/rconfig
	${INSTALL_MAN} ${WRKSRC}/rconfig.8 ${PREFIX}/man/man8/rconfig.8

.include "../../mk/bsd.pkg.mk"
