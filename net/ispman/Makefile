# $NetBSD: Makefile,v 1.1.1.1 2000/10/21 19:02:32 rh Exp $
#

DISTNAME=	ispman-0.5
WRKSRC=		${WRKDIR}/ispman
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/ispman/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.ispman.org/

DEPENDS+=	openldap>=1.2.11:../../databases/openldap
DEPENDS+=	apache>=1.3.14.1:../../www/apache
DEPENDS+=	p5-${DISTNAME}:../../net/p5-ispman

.if !exists(/usr/sbin/postfix)
DEPENDS+=	postfix>=19991231pl08:../../mail/postfix
.endif

USE_PERL5=	YES
MESSAGE_FILE=	${WRKDIR}/MESSAGE

ISPMAN_HTDOCS?=	${PREFIX}/share/ispman/virtual
ISPMAN_IP?=	127.0.0.1

do-configure:
	cd ${WRKSRC} && ${SED} < install.pl > pkginstall.pl		\
		-e 's:@@PREFIX@@:${PREFIX}:g'				\
		-e 's:@@HTDOCS@@:${ISPMAN_HTDOCS}:g'			\
		-e 's:@@IP@@:${ISPMAN_IP}:g'

do-build:
.for dir in ispman-utils ispman-web
	cd ${WRKSRC}/${dir} &&						\
	${RM} -rf `${FIND} . -name CVS -type d -print` &&		\
	for i in `${FIND} . -type f -print` ; do			\
		${CP} $$i $$i.old && 					\
		${SED} <$$i.old >$$i -e 's:/usr/bin/perl:${PERL5}:g' &&	\
		${RM} $$i.old ;						\
	done
.endfor

do-install:
	cd ${WRKSRC} && ${PERL5} ./pkginstall.pl &&			\
	${INSTALL_DATA} ispman.ldif ${PREFIX}/etc/ispman
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' < ${PKGDIR}/MESSAGE	\
		> ${WRKDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
