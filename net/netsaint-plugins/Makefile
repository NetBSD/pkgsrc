# $NetBSD: Makefile,v 1.1.1.1 2001/01/16 15:43:29 rh Exp $
#

DISTNAME=	netsaint-plugins-1.2.8-4
PKGNAME=	netsaint-plugins-1.2.8.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/

DEPENDS+=	netsaint-base-*:../../net/netsaint-base
.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-*,openssh-*}:../../security/ssh
.endif

NETSAINT_USER?=	netsaint
NETSAINT_GROUP?=${NETSAINT_USER}

USE_SSL=	YES
USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--localstatedir=/var
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/netsaint
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/netsaint
CONFIGURE_ARGS+=--libexecdir=${PREFIX}/libexec/netsaint
CONFIGURE_ARGS+=--with-lockfile=/var/run/netsaint/netsaint.lock
CONFIGURE_ARGS+=--with-netsaint-user=${NETSAINT_USER}
CONFIGURE_ARGS+=--with-netsaint-grp=${NETSAINT_GROUP}
CONFIGURE_ARGS+=--without-pgsql

.include "../../mk/bsd.pkg.mk"
