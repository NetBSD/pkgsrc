# $NetBSD: Makefile,v 1.48 2005/12/05 20:49:55 rillig Exp $

DISTNAME=	mgetty1.1.31-Jul24
PKGNAME=	mgetty-1.1.31
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/
COMMENT=	Handle external logins, send and receive faxes

BUILD_DEPENDS+=	texi2roff-[0-9]*:../../textproc/texi2roff

CONFLICTS=	hylafax-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

MAKE_ENV+=		MGETTY_CONFDIR=${PKG_SYSCONFDIR:Q}

USE_MAKEINFO=		YES
INFO_FILES=		mgetty.info
PKG_SYSCONFSUBDIR=	mgetty+sendfax

.if !defined(CONF_FILES)
. for cfg in		dialin.config		\
			faxheader		\
			faxrunq.config		\
			faxspool.rules.sample	\
			login.config		\
			mgetty.config		\
			voice.conf

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

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
