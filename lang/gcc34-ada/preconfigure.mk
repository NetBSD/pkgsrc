	# Create compiler driver scripts in ${WRKDIR}.
	(cd ${BUILDLINK_PREFIX.gcc34-ada}/bin && bin_files=`${FIND} . -type f \( -perm -0100 \)` && \
	cd ${WRKDIR}/.gcc/bin && \
	for _target_ in $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO} -n "exec ${BUILDLINK_PREFIX.gcc34-ada}/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
