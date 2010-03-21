# $NetBSD: Makefile,v 1.49 2010/03/21 16:29:40 wiz Exp $

DISTNAME=	maildrop-2.0.4
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.courier-mta.org/maildrop/

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	courier-maildir>=0.58.0:../../mail/courier-maildir

USE_TOOLS+=		gmake perl
USE_TOOLS+=		cat:run		# used by makedat(1)
USE_LANGUAGES=		c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.maildrop
PKG_SUPPORTED_OPTIONS=	authlib
PKG_SUGGESTED_OPTIONS=	authlib

.include "../../mk/bsd.options.mk"
.include "../../mail/courier-mta/Makefile.common"

# These are the users that may invoke maildrop with the "-d user"
# argument (mailbox delivery mode).
#
MAILDROP_TRUSTED_USERS?=	${REAL_ROOT_USER} ${COURIER_USER} qmaild

CONFIGURE_ARGS+=	--datadir=${DATADIR:Q}
CONFIGURE_ARGS+=	--libexecdir=${LIBEXECDIR:Q}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-makedatprog=${LIBEXECDIR:Q}/makedatprog
CONFIGURE_ARGS+=	--enable-maildirquota
CONFIGURE_ARGS+=	--enable-maildrop-uid=${REAL_ROOT_USER:Q}
CONFIGURE_ARGS+=	--enable-maildrop-gid=${COURIER_GROUP:Q}
CONFIGURE_ARGS+=	--enable-trusted-users=${MAILDROP_TRUSTED_USERS:Q}
CONFIGURE_ARGS+=	--enable-trusted-groups=${COURIER_GROUP:Q}
CONFIGURE_ARGS+=	--enable-syslog=1

###
### Support using courier-authlib to look up mail account information.
###
.if !empty(PKG_OPTIONS:Mauthlib)
CONFIGURE_ARGS+=	--enable-authlib
.  include "../../security/courier-authlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

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
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildrop/maildroptips.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildrop/README.html ${DESTDIR}${DOCDIR}/maildrop
	${INSTALL_DATA} ${WRKSRC}/maildrop/makedat.html ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/maildrop/makedat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
