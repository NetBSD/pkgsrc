# $NetBSD: Makefile,v 1.7 2010/03/21 16:29:43 wiz Exp $

DISTNAME=	bootstrap-install-sh-0.0
CATEGORIES=	regress
WRKSRC=		${WRKDIR}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test functionality of sysutils/install-sh

NO_BUILD=	yes
NO_INSTALL=	yes

INSTALL_SH?=	${WRKSRC}/install-sh

post-extract:
	${CP} ${PKGSRCDIR}/sysutils/install-sh/files/install-sh.in ${WRKSRC}

do-configure:
	${SED}	-e "s|@DEFAULT_INSTALL_MODE@|"${PKGDIRMODE}"|g"		\
		${WRKSRC}/install-sh.in > ${WRKSRC}/install-sh
	${CHMOD} +x ${WRKSRC}/install-sh

regress: configure

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

# create one directory with several nonexistent intermediate directories
regress: test-d4
test-d4:
	${INSTALL_SH} -d -m 700 ${WRKSRC}/d4_comp1/d4_comp2/d4_comp3/d4_final
	${TEST} -d ${WRKSRC}/d4_comp1/d4_comp2/d4_comp3/d4_final || exit 1
	${FIND} ${WRKSRC}/d4_comp1 -type d -exec ${LS} -ld {} \; |	\
	while read a b; do						\
		case "$$b" in						\
		*/d4_final)						\
			case "$$a" in					\
			d${MODE_7}${MODE_0}${MODE_0})			\
					exit 0 ;;			\
			*)		exit 1 ;;			\
			esac;						\
			;;						\
		*)							\
			case "$$a" in					\
			${MODE_DIR})	exit 0 ;;			\
			*)		exit 1 ;;			\
			esac;						\
			;;						\
		esac;							\
	done

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

# copy one existing file to existing file with backup
regress: test-c5
test-c5:
	${ECHO} "Test data 1" > ${WRKSRC}/c5_file1
	${ECHO} "Test data 2" > ${WRKSRC}/c5_file2
	${CP} ${WRKSRC}/c5_file2 ${WRKSRC}/c5_file2.backup
	${INSTALL_SH} -b -c ${WRKSRC}/c5_file1 ${WRKSRC}/c5_file2
	( ${CMP} ${WRKSRC}/c5_file1 ${WRKSRC}/c5_file2 && \
	  ${TEST} -f ${WRKSRC}/c5_file2.old && \
	  ${CMP} ${WRKSRC}/c5_file2.old ${WRKSRC}/c5_file2.backup ) || exit 1

# copy one existing file to existing file with backup and custom suffix
regress: test-c6
test-c6:
	${ECHO} "Test data 1" > ${WRKSRC}/c6_file1
	${ECHO} "Test data 2" > ${WRKSRC}/c6_file2
	${CP} ${WRKSRC}/c6_file2 ${WRKSRC}/c6_file2.backup
	${INSTALL_SH} -B .OLD -c ${WRKSRC}/c6_file1 ${WRKSRC}/c6_file2
	( ${CMP} ${WRKSRC}/c6_file1 ${WRKSRC}/c6_file2 && \
	  ${TEST} -f ${WRKSRC}/c6_file2.OLD && \
	  ${CMP} ${WRKSRC}/c6_file2.OLD ${WRKSRC}/c6_file2.backup ) || exit 1

# copy one existing file to existing file with numbered backup
regress: test-c7
test-c7:
	${ECHO} "Test data 1" > ${WRKSRC}/c7_file1
	${ECHO} "Test data 2" > ${WRKSRC}/c7_file2
	${ECHO} "Test data 3" > ${WRKSRC}/c7_file2.backup.0
	${ECHO} "Test data 4" > ${WRKSRC}/c7_file2.backup.1
	${ECHO} "Test data 5" > ${WRKSRC}/c7_file2.backup.2
	${CP} ${WRKSRC}/c7_file2 ${WRKSRC}/c7_file2.backup
	${INSTALL_SH} -B .backup.%i -c ${WRKSRC}/c7_file1 ${WRKSRC}/c7_file2
	( ${CMP} ${WRKSRC}/c7_file1 ${WRKSRC}/c7_file2 && \
	  ${TEST} -f ${WRKSRC}/c7_file2.backup.3 && \
	  ${CMP} ${WRKSRC}/c7_file2.backup.3 ${WRKSRC}/c7_file2.backup ) || \
	exit 1

MODES=	0 1 2 3 4 5 6 7
MODE_0=	---
MODE_1=	--x
MODE_2=	-w-
MODE_3=	-wx
MODE_4=	r--
MODE_5=	r-x
MODE_6=	rw-
MODE_7=	rwx

# Convert ${PKGDIRMODE} into the appropriate "ls" output.
MODE_DIR=	d${MODE_${PKGDIRMODE:C/(.)(.)(.)/\1/}}${MODE_${PKGDIRMODE:C/(.)(.)(.)/\2/}}${MODE_${PKGDIRMODE:C/(.)(.)(.)/\3/}}

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
