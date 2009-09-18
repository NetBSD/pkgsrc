	# $NetBSD: preconfigure.mk,v 1.1.1.1 2009/09/18 11:24:50 dmcmahill Exp $
	# Create compiler driver scripts in ${WRKDIR}.
	(${TEST} -d ${WRKDIR}/.gcc/bin || ${MKDIR} ${WRKDIR}/.gcc/bin)
	(cd ${BUILDLINK_PREFIX.gcc44}/bin && bin_files=`${LS} *` && \
	cd ${WRKDIR}/.gcc/bin && \
	for _target_ in $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO_N} "exec ${BUILDLINK_PREFIX.gcc44}/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
