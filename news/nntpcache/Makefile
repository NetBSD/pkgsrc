# $NetBSD: Makefile,v 1.4 1998/10/19 11:23:31 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1997/07/31 06:36:03 asami Exp
#

DISTNAME=		nntpcache-1.0.7.1
CATEGORIES=		news
MASTER_SITES=		ftp://nntpcache.org/pub/nntpcache/ \
			ftp://ftp.ntnu.no/pub/unix/news/ \
			ftp://ftp.nethelp.no/pub/unix/news/ \
			ftp://suburbia.net/pub/nntpcache/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nntpcache.org/

LICENSE=		fee-based-commercial-use

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=/var/spool

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d
	@-${RM} ${PREFIX}/etc/nntpcache/*.bak
.for file in config access servers spam.filter
	@${CP} ${PREFIX}/etc/nntpcache/${file} ${PREFIX}/etc/nntpcache/${file}.default
.endfor

.include "../../mk/bsd.pkg.mk"
