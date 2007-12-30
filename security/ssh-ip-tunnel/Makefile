# $NetBSD: Makefile,v 1.15 2007/12/30 09:15:36 obache Exp $

DISTNAME=	vpn-1.0
PKGNAME=	ssh-ip-tunnel-1.0
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://bleu.west.spy.net/~dustin/soft/

MAINTAINER=	dustin@spy.net
COMMENT=	Simple VPN system using pppd over ssh

DEPENDS+=	pty-redir-0.1:../../misc/pty-redir
.if !exists(/usr/bin/ssh)
DEPENDS+=	{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
SSH=		${PREFIX}/bin/ssh
.else
SSH=		/usr/bin/ssh
.endif

CONFLICTS=	vpn-1.0

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	etc/global.conf
SUBST_SED.path=		-e 's,/usr/local/bin/ssh,${SSH},g'
SUBST_SED.path+=	-e 's,/usr/pkg/bin/pty-redir,${PREFIX}/bin/pty-redir,g'

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-configure
SUBST_FILES.conf=	man/vpn.8 etc/peers/sample.peer
SUBST_SED.conf=		-e 's,/usr/pkg/etc/vpn,${PKG_SYSCONFDIR},g'

PKG_SYSCONFSUBDIR=	vpn

OWN_DIRS+=	${PKG_SYSCONFDIR}/peers
CONF_FILES+=	${PREFIX}/share/examples/vpn/global.conf ${PKG_SYSCONFDIR}/global.conf
CONF_FILES+=	${PREFIX}/share/examples/vpn/peers/sample.peer ${PKG_SYSCONFDIR}/peers/sample.peer

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
