	# Create compiler driver scripts in ${WRKDIR}.
	(test -d ${WRKDIR}/.gcc/bin || ${MKDIR} ${WRKDIR}/.gcc/bin)
	(cd ${BUILDLINK_PREFIX.gcc34}/bin && bin_files=`ls *` && \
	cd ${WRKDIR}/.gcc/bin && \
	for _target_ in $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO} -n "exec ${BUILDLINK_PREFIX.gcc34}/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
