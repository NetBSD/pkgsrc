# $NetBSD: Makefile,v 1.55 2006/10/04 20:51:40 wiz Exp $

DISTNAME=	mgetty1.1.31-Jul24
PKGNAME=	mgetty-1.1.31
PKGREVISION=	5
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://mgetty.greenie.net/
COMMENT=	Handle external logins, send and receive faxes

BUILD_DEPENDS+=	texi2roff-[0-9]*:../../textproc/texi2roff

CONFLICTS=	hylafax-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_ENV+=		MGETTY_CONFDIR=${PKG_SYSCONFDIR:Q}
MAKE_FLAGS+=		prefix=${PREFIX:Q}				\
			INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}		\
			MAN1DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man1		\
			MAN4DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man4		\
			MAN5DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man5		\
			MAN8DIR=${PREFIX:Q}/${PKGMANDIR:Q}/man8
BUILD_MAKE_FLAGS=	${MAKE_FLAGS} CONFDIR=${PKG_SYSCONFDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CONFDIR=${EXAMPLES_DIR:Q}

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
PKG_SYSCONFSUBDIR=	mgetty+sendfax

.for cfg in		dialin.config		\
			faxheader		\
			faxrunq.config		\
			faxspool.rules.sample	\
			login.config		\
			mgetty.config		\
			voice.conf

CONF_FILES+=		${EXAMPLES_DIR}/${cfg} ${PKG_SYSCONFDIR}/${cfg}
.endfor

PKG_GROUPS=		dialer
PKG_USERS=		fax:dialer

EXAMPLES_DIR=		${PREFIX}/share/examples/mgetty+sendfax
OWN_DIRS_PERMS+=	/var/spool/fax ${ROOT_USER} ${ROOT_GROUP} 755
OWN_DIRS_PERMS+=	/var/spool/fax/incoming ${ROOT_USER} ${ROOT_GROUP} 755
OWN_DIRS_PERMS+=	/var/spool/fax/outgoing fax ${ROOT_GROUP} 755

.include "../../graphics/netpbm/buildlink3.mk"

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

.include "../../mk/bsd.pkg.mk"
