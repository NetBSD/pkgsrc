# $NetBSD: Makefile,v 1.26 2003/02/27 17:13:37 fredb Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.28-Jan10
PKGNAME=	mgetty-1.1.28
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/
COMMENT=	Handle external logins, send and receive faxes

CONFLICTS=	hylafax-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes

MAKE_ENV=		MGETTY_CONFDIR=${PKG_SYSCONFDIR}
WRKSRC=			${WRKDIR}/${PKGNAME:C/nb[0-9]//}

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

_EXAMPLES_DIR=		${PREFIX}/share/examples/mgetty+sendfax

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
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
