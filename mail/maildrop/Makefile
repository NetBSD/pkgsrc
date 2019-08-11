# $NetBSD: Makefile,v 1.68 2019/08/11 13:21:28 wiz Exp $

DISTNAME=	maildrop-3.0.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.courier-mta.org/maildrop/

DEPENDS+=	courier-maildir>=${COURIER_VERSION}:../../mail/courier-maildir

USE_TOOLS+=		gmake perl pkg-config
USE_TOOLS+=		cat:run		# used by makedat(1)
USE_LANGUAGES=		c c++

.include "options.mk"
.include "../../mail/courier-mta/Makefile.common"

DOCFILES=	README README.postfix README.dovecotauth maildroptips.txt

# These are the users that may invoke maildrop with the "-d user"
# argument (mailbox delivery mode).
MAILDROP_TRUSTED_USERS?=${REAL_ROOT_USER} ${COURIER_USER} ${QMAIL_DAEMON_USER}
BUILD_DEFS+=		QMAIL_DAEMON_USER

CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--libexecdir=${LIBEXECDIR}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-makedatprog=${LIBEXECDIR}/makedatprog
CONFIGURE_ARGS+=	--enable-maildirquota
CONFIGURE_ARGS+=	--enable-maildrop-uid=${REAL_ROOT_USER}
CONFIGURE_ARGS+=	--enable-maildrop-gid=${COURIER_GROUP}
CONFIGURE_ARGS+=	--enable-trusted-users=${MAILDROP_TRUSTED_USERS:Q}
CONFIGURE_ARGS+=	--enable-trusted-groups=${COURIER_GROUP}
CONFIGURE_ARGS+=	--enable-syslog=1

INSTALL_AM_MAKEFLAGS+=	htmldir=${DOCDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

REQD_DIRS=	${DATADIR} ${DOCDIR} ${LIBEXECDIR}

# Note special permissions for some binaries.  These are set to match
# the defaults from a courier-mta installation.
#
SPECIAL_PERMS=	bin/lockmail ${REAL_ROOT_USER} ${COURIER_GROUP} 755
SPECIAL_PERMS+=	bin/maildrop ${REAL_ROOT_USER} ${COURIER_GROUP} 4555

.include "../../devel/sysexits/buildlink3.mk"

INSTALLATION_DIRS=	libexec/courier ${DOCDIR}/maildrop share/courier

post-install:
.for aaa in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${aaa} ${DESTDIR}${DOCDIR}/maildrop
.endfor
	${INSTALL_MAN} ${WRKSRC}/libs/maildrop/makedat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
#	${INSTALL_DATA} ${WRKSRC}/libs/maildrop/makedat.html ${DESTDIR}${DOCDIR}

.include "../../mail/courier-unicode/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
