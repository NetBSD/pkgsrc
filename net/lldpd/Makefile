# $NetBSD: Makefile,v 1.12 2015/01/15 13:54:40 mef Exp $

DISTNAME=		lldpd-0.7.13
CATEGORIES=		net
MASTER_SITES=		http://media.luffy.cx/files/lldpd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vincentbernat.github.com/lldpd/
COMMENT=		802.1ab (LLDP) implementation
LICENSE=		isc
# `lldpcli` will be linked to GNU Readline (which is GPL licensed)
# if available. To avoid this, use `--without-readline` as a configure
# option.

# interfaces-bsd.c:45:34: error: net/agr/if_agrioctl.h: No such file or directory
NOT_FOR_PLATFORM=	NetBSD-5*-*
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-privsep-chroot=${PKG_HOME._lldpd}
# run/lldpd.socket is created under this directory
# (the default is ${PRERIX}/var, changed since 0.7.9)
CONFIGURE_ARGS+=       --localstatedir=${VARBASE}
BUILD_DEFS+=		VARBASE

CONF_FILES=		${EXAMPLE_DIR}/README.conf etc/lldpd.d/README.conf
CONF_FILES+=		${EXAMPLE_DIR}/lldpcli.bash-completion \
	         etc/bash_completion.d/lldpcli.bash-completion
EXAMPLE_DIR=		${PREFIX}/share/${PKGBASE}/conf

#  CCLD     lldpd
#  ld: cannot find -lperl
LDFLAGS+=		-L${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/CORE

RCD_SCRIPTS=		lldpd
PKG_GROUPS=		_lldpd
PKG_USERS=		_lldpd:_lldpd
PKG_HOME._lldpd=	${VARBASE}/chroot/lldpd

OWN_DIRS=		${VARBASE}/chroot/lldpd
AUTO_MKDIRS=		yes

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/${PKGBASE}/conf

.include "options.mk"

post-install:
.for i in etc/lldpd.d/README.conf etc/bash_completion.d/lldpcli.bash-completion
	 ${MV} ${DESTDIR}${PREFIX}/${i} ${DESTDIR}${EXAMPLE_DIR}
.endfor

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.5
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
