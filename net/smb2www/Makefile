# $NetBSD: Makefile,v 1.1.1.1 2001/02/18 04:52:34 hubertf Exp $
#

DISTNAME=	smb2www-980804
CATEGORIES=	net
MASTER_SITES=	http://us1.samba.org/samba/smb2www/ \
		http://www.samba.org/samba/smb2www/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.samba.org/samba/smb2www/
COMMENT=	Gateway to Windows networking

DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=	samba-[0-9]*:../../net/samba
DEPENDS+=	perl-[0-9]*:../../lang/perl5
DEPENDS+=	apache{,6}-[0-9]*:../../www/apache

NO_WRKSUBDIR=	yes

SMB2WWW_MASTER_BROWSER_SERVER?=		# set for non-empty
APACHE_USER?=	nobody
DESCR_SRC=	${WRKSRC}/.DESCRX
NO_BUILD=	yes

pre-install:
		if [ -d ${PREFIX}/libexec/smb2www ]; then \
			${ECHO} "" ; \
			${ECHO} "----------------------------------------------" ; \
			${ECHO} "Please remove ${PREFIX}/libexec/smb2www first!" ; \
			${ECHO} "----------------------------------------------" ; \
			${ECHO} "" ; \
			exit 1 ; \
		fi

do-install:
		cd ${WRKSRC} ; \
		( \
		${ECHO} "" ; \
		${ECHO} "${APACHE_USER}" ; \
		${ECHO} "nobody" ; \
		${ECHO} "${PREFIX}/libexec/smb2www" ; \
		${ECHO} "${LOCALBASE}/bin" ; \
		${ECHO} "${LOCALBASE}/bin/perl" ; \
		${ECHO} "${SMB2WWW_MASTER_BROWSER_SERVER}" ; \
		${ECHO} "english" ; \
		${ECHO} "/smb2www/images" ; \
		${ECHO} "/smb2www" ; \
		${ECHO} "${LOCALBASE}/etc/httpd" ; \
		) | perl Install.pl

post-install:
		${SED} \
			's,@PREFIX@,${PREFIX},' \
			<${PKGDIR}/DESCR >${DESCR_SRC}

.include "../../mk/bsd.pkg.mk"
