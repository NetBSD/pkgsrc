# $NetBSD: Makefile,v 1.11 2006/02/03 02:04:27 rillig Exp $

DISTNAME=	webmin-1.170-minimal
PKGNAME=	${DISTNAME:S/-minimal$//}
PKGREVISION=	2
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=webadmin/}

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.webmin.com/
COMMENT=	Perl web server and CGI for Unix system administration

DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# empty
NO_BUILD=	yes

USE_TOOLS+=	perl:run
REPLACE_PERL+=	*.cgi */*.cgi *.pl */*.pl

WEBMIN_DIR=		${PREFIX}/${WEBMIN_SUBDIR}
WEBMIN_SUBDIR=		share/webmin
WEBMIN_ETCDIR?=		${PKG_SYSCONFDIR}/webmin
WEBMIN_LOGDIR?=		${VARBASE}/log/webmin
FILES_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}
FILES_SUBST+=		WEBMIN_ETCDIR=${WEBMIN_ETCDIR:Q}
FILES_SUBST+=		WEBMIN_LOGDIR=${WEBMIN_LOGDIR:Q}
MESSAGE_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
RCD_SCRIPTS=		webmin
OWN_DIRS=		${WEBMIN_LOGDIR}

# Dynamically generate the Webmin PLIST from the installed files.
WEBMIN_PLIST_FILES_CMD= \
	( cd ${PREFIX}; ${FIND} ${WEBMIN_SUBDIR} \! -type d -print )	\
	| ${SORT} -u
WEBMIN_PLIST_DIRS_CMD= \
	( cd ${PREFIX}; ${FIND} ${WEBMIN_SUBDIR} -type d -print )	\
	| ${SED} -e "s,^,@unexec ${RMDIR} -p %D/,"			\
		 -e "s,\$$, 2>/dev/null || ${TRUE},"			\
	| ${SORT} -ur
GENERATE_PLIST+=	${WEBMIN_PLIST_FILES_CMD}; ${WEBMIN_PLIST_DIRS_CMD};

do-configure:
	for file in ${WRKSRC}/setup.sh; do				\
		${SED}	-e "s|/etc/webmin|${WEBMIN_ETCDIR}|g"		\
			-e "s|/var/webmin|${WEBMIN_LOGDIR}|g"		\
			-e "s|/usr/bin/perl|${PERL5}|g"			\
			-e "/chown.*root/s|root|${ROOT_USER}|g"		\
			-e "/chgrp.*bin/s|bin|${ROOT_GROUP}|g"		\
			$$file > $$file.new;				\
		if [ -x $$file ]; then					\
			${CHMOD} +x $$file.new;				\
		fi;							\
		${MV} -f $$file.new $$file;				\
	done
	case "${USE_BUILTIN.openssl}" in				\
	[nN][oO])							\
		for file in ${WRKSRC}/acl/config ${WRKSRC}/acl/config-*; do \
			${SED}	-e "s|^ssleay=.*|ssleay=${SSLBASE}/bin/openssl|" \
				$$file > $$file.new;			\
			${MV} -f $$file.new $$file;			\
		done;							\
		;;							\
	esac

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${WEBMIN_DIR}
	${CP} -R ${WRKSRC}/* ${WEBMIN_DIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
