	# Create compiler driver scripts in ${WRKDIR}.
	(cd ${BUILDLINK_PREFIX.gcc-3.4}/bin && bin_files=`ls *` && \
	cd ${WRKDIR}/.gcc/bin && \
	for _target_ in $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO} -n "exec ${LOCALBASE}/gcc-3.4.0/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
