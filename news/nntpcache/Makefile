# $NetBSD: Makefile,v 1.5 1999/02/23 00:38:04 tv Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/01 03:04:11 itojun Exp
#

DISTNAME=		nntpcache-2.3.3
CATEGORIES=		news
MASTER_SITES=		ftp://nntpcache.org/pub/nntpcache/ \
			ftp://ftp.ntnu.no/pub/unix/news/ \
			ftp://ftp.nethelp.no/pub/news/ \
			ftp://suburbia.net/pub/nntpcache/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nntpcache.org/

LICENSE=		fee-based-commercial-use

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=/var/spool
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_GMAKE=		yes

INSTALL_TARGET=		SUBDIRS="cf src filters http doc pgp contrib/newshound innreport" \
			install

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nntpcache
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ FAQ.html LICENSING \
		${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
