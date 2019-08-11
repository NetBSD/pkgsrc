# $NetBSD: Makefile,v 1.66 2019/08/11 13:23:02 wiz Exp $
#

PKGNAME=		amanda-client-${AMANDA_VERSION}
PKGREVISION=		1

COMMENT=		Client part of Amanda, a network backup system

CONFIGURE_ARGS+=	--without-server --without-gnuplot

BUILD_DIRS=		gnulib
BUILD_DIRS+=		client-src application-src
BUILD_DIRS+=		recover-src oldrecover-src

MANPAGES+=		amanda-applications.7
MANPAGES+=		amdump_client.8
MANPAGES+=		amgtar.8
MANPAGES+=		ampgsql.8
MANPAGES+=		amraw.8
MANPAGES+=		amrecover.8
MANPAGES+=		amsamba.8
MANPAGES+=		amstar.8
MANPAGES+=		amsuntar.8
MANPAGES+=		amzfs-snapshot.8
MANPAGES+=		amzfs-sendrecv.8

PERL5_MODS+=		Amanda/Application.pm
PERL5_MODS+=		Amanda/Application/Zfs.pm

PERL5_LIBS+=		Application

.include "../../sysutils/amanda-common/Makefile.common"

.if !empty(PKG_OPTIONS:Mamanda-smb)
CONFIGURE_ARGS+=	--with-smbclient
DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba
.endif

.if !empty(PKG_OPTIONS:Mamanda-dump-snap)
CONFIGURE_ARGS+=	--with-dump-use-snapshot --with-rundump
.endif

PLIST_VARS+=		amanda-bsdtar
.if !empty(PKG_OPTIONS:Mamanda-bsdtar)
MANPAGES+=		ambsdtar.8
SPECIAL_PERMS+=		libexec/amanda/application/ambsdtar ${AM_PROG_PERMS}
PLIST.amanda-bsdtar=	yes
.endif

SPECIAL_PERMS+=		libexec/amanda/application/amgtar ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/application/amstar ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/calcsize ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/killpgrp ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/rundump ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/runtar ${AM_PROG_PERMS}

post-build:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC}/amandad-src &&		\
		${BUILD_MAKE_CMD} amandad

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amandad-src/amandad		\
		${DESTDIR}${PREFIX}/libexec/amanda

.include "../../sysutils/amanda-common/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
