# $NetBSD: Makefile,v 1.36.2.1 2003/12/30 16:19:32 agc Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.30-Dec16
PKGNAME=	mgetty-1.1.30
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/
COMMENT=	Handle external logins, send and receive faxes

BUILD_DEPENDS+=	texi2roff-[0-9]*:../../textproc/texi2roff

CONFLICTS=	hylafax-[0-9]*

USE_BUILDLINK2=		yes

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

MAKE_ENV=		MGETTY_CONFDIR=${PKG_SYSCONFDIR}

USE_MAKEINFO=		YES
INFO_FILES=		mgetty.info
PKG_SYSCONFSUBDIR=	mgetty+sendfax

.ifndef CONF_FILES
. for cfg in		dialin.config		\
			faxheader		\
			faxrunq.config		\
			faxspool.rules.sample	\
			login.config		\
			mgetty.config
CONF_FILES+=		${_EXAMPLES_DIR}/${cfg} ${PKG_SYSCONFDIR}/${cfg}
. endfor
.endif

PKG_GROUPS=		dialer
PKG_USERS=		fax:dialer

_EXAMPLES_DIR=		${PREFIX}/share/examples/mgetty+sendfax
MAKE_DIRS_PERMS+=	/var/spool/fax ${ROOT_USER} ${ROOT_GROUP} 755
MAKE_DIRS_PERMS+=	/var/spool/fax/incoming ${ROOT_USER} ${ROOT_GROUP} 755
MAKE_DIRS_PERMS+=	/var/spool/fax/outgoing fax ${ROOT_GROUP} 755

do-configure:
	${MV} ${WRKSRC}/doc/fax.1in ${WRKSRC}/doc/sendfax.1in
	cd ${WRKSRC}						\
	&& for _file in faxrunq.config policy.h-dist;		\
	do							\
		${MV} $$_file $${_file}.orig;			\
		${SED} 's|/usr/local|${PREFIX}|'		\
		    $${_file}.orig > $$_file;			\
	done							\
	&& cd ${.CURDIR}					\
	&& ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include "../../graphics/netpbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
