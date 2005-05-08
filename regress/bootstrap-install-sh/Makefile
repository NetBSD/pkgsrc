# $NetBSD: Makefile,v 1.1.1.1 2005/05/08 09:51:26 jlam Exp $

DISTNAME=	bootstrap-install-sh-0.0
CATEGORIES=	regress
WRKSRC=		${WRKDIR}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Test functionality of bootstrap install-sh

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_INSTALL=	yes
NO_PACKAGE=	yes

INSTALL_SH=	${WRKSRC}/install-sh

regress: extract
post-extract:
	${CP} ${FILESDIR}/install-sh ${INSTALL_SH}
	${CHMOD} +x ${INSTALL_SH}

# create one directory using -d
regress: test-d1
test-d1:
	${INSTALL_SH} -d ${WRKSRC}/d1_dir
	${TEST} -d ${WRKSRC}/d1_dir || exit 1

# create two directories using -d
regress: test-d2
test-d2:
	${INSTALL_SH} -d ${WRKSRC}/d2_dir1 ${WRKSRC}/d2_dir2
	( ${TEST} -d ${WRKSRC}/d2_dir1 && \
	  ${TEST} -d ${WRKSRC}/d2_dir2 ) || exit 1

# create three directories using -d
regress: test-d3
test-d3:
	${INSTALL_SH} -d ${WRKSRC}/d3_dir1 ${WRKSRC}/d3_dir2 ${WRKSRC}/d3_dir3
	( ${TEST} -d ${WRKSRC}/d3_dir1 && \
	  ${TEST} -d ${WRKSRC}/d3_dir2 && \
	  ${TEST} -d ${WRKSRC}/d3_dir3 ) || exit 1

# copy one existing file to nonexistent file
regress: test-c1
test-c1:
	${ECHO} "Test data" > ${WRKSRC}/c1_file1
	${INSTALL_SH} -c ${WRKSRC}/c1_file1 ${WRKSRC}/c1_file2
	${CMP} ${WRKSRC}/c1_file1 ${WRKSRC}/c1_file2 || exit 1

# copy one existing file into existing directory
regress: test-c2
test-c2:
	${ECHO} "Test data" > ${WRKSRC}/c2_file
	${MKDIR} ${WRKSRC}/c2_dir
	${INSTALL_SH} -c ${WRKSRC}/c2_file ${WRKSRC}/c2_dir
	${CMP} -s ${WRKSRC}/c2_file ${WRKSRC}/c2_dir/c2_file || exit 1

# copy two existing files into existing directory
regress: test-c3
test-c3:
	${ECHO} "Test data 1" > ${WRKSRC}/c3_file1
	${ECHO} "Test data 2" > ${WRKSRC}/c3_file2
	${MKDIR} ${WRKSRC}/c3_dir
	${INSTALL_SH} -c ${WRKSRC}/c3_file1 ${WRKSRC}/c3_file2 ${WRKSRC}/c3_dir
	( ${CMP} -s ${WRKSRC}/c3_file1 ${WRKSRC}/c3_dir/c3_file1 && \
	  ${CMP} -s ${WRKSRC}/c3_file2 ${WRKSRC}/c3_dir/c3_file2 ) || exit 1

# copy three existing files into existing directory
regress: test-c4
test-c4:
	${ECHO} "Test data 1" > ${WRKSRC}/c4_file1
	${ECHO} "Test data 2" > ${WRKSRC}/c4_file2
	${ECHO} "Test data 3" > ${WRKSRC}/c4_file3
	${MKDIR} ${WRKSRC}/c4_dir
	${INSTALL_SH} -c ${WRKSRC}/c4_file1 ${WRKSRC}/c4_file2 \
		${WRKSRC}/c4_file3 ${WRKSRC}/c4_dir
	( ${CMP} -s ${WRKSRC}/c4_file1 ${WRKSRC}/c4_dir/c4_file1 && \
	  ${CMP} -s ${WRKSRC}/c4_file2 ${WRKSRC}/c4_dir/c4_file2 && \
	  ${CMP} -s ${WRKSRC}/c4_file3 ${WRKSRC}/c4_dir/c4_file3 ) || exit 1

MODES=	0 1 2 3 4 5 6 7
MODE_0=	---
MODE_1=	--x
MODE_2=	-w-
MODE_3=	-wx
MODE_4=	r--
MODE_5=	r-x
MODE_6=	rw-
MODE_7=	rwx

# test mode permissions on installing file to nonexisting file
regress: test-m1
test-m1:
.for _u_ in ${MODES}
.  for _g_ in ${MODES}
.    for _o_ in ${MODES}
	${ECHO} "Test data" > ${WRKSRC}/m${_u_}${_g_}${_o_}_file1
	${INSTALL_SH} -m ${_u_}${_g_}${_o_} ${WRKSRC}/m${_u_}${_g_}${_o_}_file1 ${WRKSRC}/m${_u_}${_g_}${_o_}_file2
	${LS} -l ${WRKSRC}/m${_u_}${_g_}${_o_}_file2 |			\
	while read a b; do						\
		case "$$a" in						\
		-${MODE_${_u_}}${MODE_${_g_}}${MODE_${_o_}})		\
			exit 0 ;;					\
		*)	exit 1 ;;					\
		esac;							\
	done
.    endfor
.  endfor
.endfor

# test mode permissions on creating directory
regress: test-m2
test-m2:
.for _u_ in ${MODES}
.  for _g_ in ${MODES}
.    for _o_ in ${MODES}
	${INSTALL_SH} -m 357 -d ${WRKSRC}/m357_dir
	${INSTALL_SH} -m ${_u_}${_g_}${_o_} -d ${WRKSRC}/m${_u_}${_g_}${_o_}_dir
	${LS} -l ${WRKSRC}/m${_u_}${_g_}${_o_}_file2 |			\
	while read a b; do						\
		case "$$a" in						\
		-${MODE_${_u_}}${MODE_${_g_}}${MODE_${_o_}})		\
			exit 0 ;;					\
		*)	exit 1 ;;					\
		esac;							\
	done
.    endfor
.  endfor
.endfor

pre-clean:
	${TEST} "`${ECHO} ${WRKSRC}/*`" = "${WRKSRC}/*" ||		\
		${CHMOD} -R u+rwx ${WRKSRC}/*

.include "../../mk/bsd.pkg.mk"
