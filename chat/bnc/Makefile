# $NetBSD: Makefile,v 1.5 2001/09/27 23:17:48 jlam Exp $
# FreeBSD Id: ports/irc/bnc/Makefile,v 1.9 2000/05/22 06:38:58 will Exp

DISTNAME=	bnc2.8.2
PKGNAME=	bnc-2.8.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://bnc.dragondata.com
COMMENT=	Simple IRC relay proxy with support for virtual hosting

DEPENDS+=	dialog-[0-9]*:../../misc/dialog

GNU_CONFIGURE=	YES

MAKE_ENV+=	OPTS="${CFLAGS}"

post-patch:
	${SED}	-e "s,./mkpasswd,${PREFIX}/bin/bncmkpasswd,g"		\
		-e "s,dialog --,${LOCALBASE}/bin/dialog --,g"		\
		${WRKSRC}/bncsetup > ${WRKSRC}/bncsetup.done
	${MV} ${WRKSRC}/bncsetup.done ${WRKSRC}/bncsetup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncchk ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncsetup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkpasswd ${PREFIX}/bin/bncmkpasswd
	${INSTALL_DATA} ${WRKSRC}/example.conf 				\
		${PREFIX}/share/examples/bnc.conf.sample
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bnc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bnc

.include "../../mk/bsd.pkg.mk"
